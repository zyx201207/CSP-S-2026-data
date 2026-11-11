#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+50;
ll f[N];char c[N];
ll slen=0,res=0,n=0;
ll lenn;
ll start[N],ed[N];
//start idx,end idx
//1 based
int main(){
    freopen("string.in","r",stdin);//T2: 9:05~9:40
    freopen("string.out","w",stdout);//hp:100
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //check and PACK!
    //answer:had done
    cin>>lenn;
    for(ll i=1;i<=lenn;i++){
        ll a;char b;cin>>a>>b;
        if(b==c[n]){
            f[n]+=a;
            continue;
        }n++;
        f[n]=a;c[n]=b;

    }for(ll i=1;i<=n;i++){
        start[i]=slen+1;
        slen+=f[i];
        ed[i]=slen;
    }
    ll lz,rz;//wei yu zifuchuan de xiabiao
    ll lidx=0,ridx=0;//dangqian shu zu de xiabiao
    if(slen%2){
        lz=slen/2+1,rz=slen/2+1;
    }else{
        slen++;
        bool flag=0;
        for(ll i=1;i<=n;i++){
            if(start[i]<=slen/2+1&&ed[i]>=slen/2+1&&!flag){
                ed[i]++;
                flag=1;
            }else if(flag){
                start[i]++;ed[i]++;
            }
        }
        lz=slen/2+1,rz=slen/2+1;
    }bool flag1=1,flag2=1;
    for(ll i=1;i<=n;i++){
        if(ed[i]>=lz&&flag1){
            lidx=i;
            flag1=0;
            //break;
        }if(ed[i]>=rz&&flag2){
            ridx=i;
            flag2=0;
            //break;
        }
    }
    //cout<<lidx<<" "<<ridx<<" "<<lz<<" "<<rz<<"\n";
    while(lidx>=1&&ridx<=n&&lz>=1&&rz<=slen){
        //get addlen
        ll addlen=min(abs(start[lidx]-lz),abs(ed[ridx]-rz));//wang liangduan yan shen de chang du
        //check will it join the next char
        if(lz<=start[lidx]){
            lidx--;
        }if(rz>=ed[ridx]){
            ridx++;
        }
        //add the ans
        if(c[lidx]!=c[ridx]){
            res+=addlen;
        }
        //add point
        lz-=addlen,rz+=addlen;

       //cout<<lidx<<" "<<ridx<<" "<<lz<<" "<<rz<<"\n";
    }
    cout<<res;
    return 0;
}
