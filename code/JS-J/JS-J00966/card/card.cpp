#include<bits/stdc++.h>
using namespace std;
vector<int> card;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("/home/user/Desktop/card/card5.in","r",stdin);
    //freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        card.push_back(temp);
    }
    map<int,int> res;
    //cout<<"input successfully"<<endl;
    for(int i=0;i<n;i++){
        map<int,int> location;
        vector<int> desktop;
        for(int i=1;i<=m;i++){
            location[i]=-1;
        }
        //cout<<"create list,map successfully"<<endl;
        for(int j=i;j<n;j++){
            int crt_card=card[j];
            if(location[crt_card]==-1){
                desktop.push_back(crt_card);
                location[crt_card]=desktop.size()-1;
                //cout<<"put card "<<crt_card<<" on "<<location[crt_card]<<endl;
            }else{
                int crt_index=location[crt_card];
                int len=desktop.size();
                for(int i=crt_index;i<len;i++){
                    int crt_num=desktop[i];
                    //cout<<"delete card "<<desktop[i]<<" on "<<i<<endl;
                    location[crt_num]=-1;
                    desktop.pop_back();
                }
                desktop.push_back(crt_card);
                location[crt_card]=desktop.size()-1;
                //cout<<"finish deleting from "<<crt_index<<" to "<<len-1<<endl;
                //cout<<"put card "<<crt_card<<" on "<<location[crt_card]<<endl;
            }
            //cout<<"put card successfully"<<endl;
        }
        //cout<<"break inside cycle successfully"<<endl;
        for(int i=1;i<=m;i++){
            //cout<<"go into counting cycle successfully"<<endl;
            int crt_index=location[i];
            //cout<<"num: "<<i<<",index: "<<crt_index<<endl;
            if(crt_index>-1){
                //cout<<"has number "<<i<<" , add 1"<<endl;
                res[i]++;
                //cout<<i<<":"<<res[i]<<endl;
            }
        }
        //cout<<"count successfully"<<endl;
        //cout<<"To the next cycle: "<<i+1<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
}
