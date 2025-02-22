#include <bits/stdc++.h>

using namespace std;

#define mem(v,i) memset(v,i,sizeof(v))

#define nl cout<<endl
#define el cerr<<endl

#define rStringLen 100
#define pageTypes 20

#define repp(i,n) for(int i=(0);i<(n);i++)
#define rep(i,a,n) for(int i=(a);i<(n);i++)

int pgFaultsFIFO(vector<int> pages, int capacity){
    int n = pages.size();

    int pgFault  = 0;
    queue<int> fifo;
    unordered_set<int> present;

    repp(i, n){
        int page = pages[i];
        if(present.find(page) != present.end()) continue;

        if(fifo.size() >= capacity){
            int rem = fifo.front();
            fifo.pop();
            present.erase(rem);
            // cerr<<"Rem=>"<<rem<<endl;
        }

        fifo.push(page);
        present.insert(page);

        pgFault++;
        // cerr<<page<<endl;
    }
    // cerr<<endl;
    return pgFault;
}

int pgFaultsLRU(vector<int> pages, int capacity){
    int n = pages.size();

    int pgFault  = 0;
    vector<int> lru;
    unordered_set<int> present;

    repp(i, n){
        int page = pages[i];
        if(present.find(page) != present.end()){
            for (auto it = lru.begin(); it != lru.end(); ++it){
                if(*it==page) lru.erase(it);
            }
            lru.push_back(page);
        } else{
            if(lru.size() >= capacity){
                int rem = lru.front();
                lru.erase(lru.begin());
                present.erase(rem);
            }

            lru.push_back(page);
            present.insert(page);

            pgFault++;
        } 
    }
    return pgFault;
}


int pgFaultsOPR(vector<int> pages, int capacity){
    int n = pages.size();

    int pgFault  = 0;
    vector<int> opr;
    unordered_set<int> present;

    repp(i, n){
        int page = pages[i];
        if(present.find(page) != present.end()) continue;

        if(opr.size() >= capacity){
            int num = -1;
            int num_pos = -1;
            for (auto& it : opr){
                int tnum = it, tnum_pos = -1;
                for(int j = i+1; j < n; j++){
                    if(pages[j]==it){
                        tnum_pos = j;
                    }
                }
                if(tnum_pos==-1){
                    num = tnum;
                    num_pos = tnum_pos;
                    break;
                } else if(num!=-1){
                    if(tnum_pos>num_pos){
                        num = tnum;
                        num_pos = tnum_pos;
                    }
                } else{
                    num = tnum;
                    num_pos = tnum_pos;
                }
            }

            for (int it1 = 0; it1 < opr.size(); ++it1){
                if(it1==num) opr.erase(opr.begin()+it1);
            }
            
            present.erase(num);
        }

        opr.push_back(page);
        present.insert(page);

        pgFault++;

    }
    return pgFault;
}

int main(){

    int n_frames;
    cout<<"Enter the number of frames: ";
    cin>>n_frames;

    vector<int> rString;

    cout<<"Enter the pages(positive integers) space seperated: \n";

    while (true) {
        int temp;
        cin >> temp;
        if(temp == -1) break;

        rString.push_back(temp);
        if (cin.peek() == '\n') {
            break;
        }
    }
    nl;
    cout<<"Page Faults in FIFO: "<<pgFaultsFIFO(rString, n_frames)<<endl;
    cout<<"Page Faults in LRU: "<<pgFaultsLRU(rString, n_frames)<<endl;
    cout<<"Page Faults in OPR: "<<pgFaultsOPR(rString, n_frames)<<endl;
    
    cout<<"\nChecking for Belady’s anomaly\nPlease enter the number of simulations: ";
    int n;
    cin>>n;
    nl;

    srand(time(0));

    repp(i,n){
        int inp_string;
        rString.clear();

        repp(j, rStringLen) rString.push_back(rand()%pageTypes);

        int lastFault = INT_MAX;

        rep(j, 2, rStringLen/5){
            int currFault = pgFaultsFIFO(rString, j);
            if(currFault>lastFault){
                cout<<"Belady’s Anomaly detected.\n";
                cout<<"\tNumber of frames: "<<j-1<<"\tFaults: "<<lastFault;nl;
                cout<<"\tNumber of frames: "<<j<<"\tFaults: "<<currFault;nl;
            }
            lastFault = currFault;
        }
    }
    return 0;
}