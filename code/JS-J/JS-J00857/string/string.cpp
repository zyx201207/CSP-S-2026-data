#include <bits/stdc++.h>
using namespace std;
pair<int,char>ms[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;long long length=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ms[i].first>>ms[i].second;
        length+=ms[i].first;
    }
    if(length<=1e5){
        string temp="";
        for(int i=1;i<=n;i++){
            string temp2(ms[i].first,ms[i].second);
            temp+=(temp2);
            //cout<<temp2<<endl;
        }
        //cout<<temp<<" ";
        for(int i=length-1,j=0;i>=j;i--,j++){
            if(temp[i]!=temp[j]){
                ans++;
            }
        }
    }
    else{
        //length is too much,I should find other way.
        int npos_t=1,mpos_t=n,lmissed=ms[1].first,rmissed=ms[n].first;
        while(npos_t<mpos_t){
            int missed=min(lmissed,rmissed);
            //if ms[npos_t,&secondww] is different as ms[mpos_t,&secondww],ans add missed;
            if(ms[npos_t].second != ms[mpos_t].second){ans+=missed;}
            //calc new numbers.
            if(lmissed==rmissed){
                npos_t++;mpos_t--;lmissed=ms[npos_t].first,rmissed=ms[mpos_t].first;
            }
            else if(lmissed>rmissed){
                mpos_t--;lmissed-=rmissed;rmissed=ms[mpos_t].second;
            }
            else{
                npos_t++;rmissed-=lmissed;lmissed=ms[npos_t].second;
            }

        }
    }
    cout<<ans;
    return 0;
}
//
