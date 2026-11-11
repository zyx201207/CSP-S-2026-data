#include<bits/stdc++.h>

using namespace std;
int w[500010],k[1000],a[1000],t[1000],xxr[100010],yyr[100010];
int lu[1010][1010],da[1010],yy=1,cnt,ans;
int c,n,m,d,q;
int te(int num,int fi){
	for(int i=1;i<=n;i++){
		if(lu[num][i]==1){
			if(fi==0){
				da[yy++]=i;
				break;
			}
			if(i==fi){
				da[yy++]=i;
				fi=0;
			}
			else return te(i,fi);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.ont","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i]>>t[i];
	}
	for(int i=1;i<=q;i++)cin>>xxr[i]>>yyr[i];
	for(int i=1;i<=n;i++){
		lu[a[1]][a[2]]=1;
		lu[a[2]][a[1]]=1;
	}	
	for(int i=1;i<=q;i++){
		cnt=0;
		te(xxr[i],yyr[i]);
		for(int i=yy-2;i>=1;i--){
		    cnt+=w[da[i]];
		    cnt+=k[da[i]];
	    }
	    cnt+=w[da[i]];
	    ans=max(ans,cnt);
	}
    cout<<ans;
	return 0;
} 
