#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
string abin[200005];
bool choose[200005];
bool nowok[200005];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        int temp=a[i];
        while(temp){
            abin[i]=(temp%2==0?'0':'1')+abin[i];
            temp/=2;
        }
        while(abin[i].length()<=30)abin[i]='0'+abin[i];
        choose[i]=1;
    }
    int left=n;
    for(int i=1;i<=30;i++){//place of the bin number
        int cnt=0;
        for(int j=1;j<=n;j++)nowok[j]=0;
        for(int j=1;j<=n;j++){
            if(abin[j][i]=='1'){
                nowok[j]=1;
                cnt++;
            }
        }
        if(cnt>=m){
            for(int j=1;j<=n;j++){
                if(nowok[j]==0){
                    choose[j]=0;
                    left--;
                }
                if(left==m)break;
            }
        }
        if(left==m)break;
    }
    int ans=(1<<30)-1;
    for(int i=1;i<=n&&left;i++){
        if(choose[i]){
            ans&=a[i];
            left--;
        }
        //cout<<choose[i]<<' ';
    }
    cout<<ans;
	return 0;
}
