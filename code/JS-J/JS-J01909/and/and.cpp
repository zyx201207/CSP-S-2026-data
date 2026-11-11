#include<bits/stdc++.h>
using namespace std;
int b[200005][32],maxn=-1,a[200005],m,n,ans,maxnn;
void ds(){
	int c[200005];
	int s=0;
	for(int i=1;i<=n;i++){
		if(b[i][maxn]==1){
			s++;
			c[s]=i;
			//cout<<i<<endl;
		}
	}
	for(int i=1;i<=s;i++)cout<<c[i]<<" ";
	cout<<"   "<<maxn<<" "<<s<<endl;
	if(s==m){
		for(int i=1;i<=32;i++){
			int fl=1;
			for(int j=1;j<=m;j++){
				if(b[c[j]][i]==0)fl=0;
			}
			if(fl==1){
				int yyy=1;
				for(int j=1;j<i;j++)yyy*=2;
				ans+=yyy;
			}
		}
		//cout<<1;
		}else if(s>m){
			for(int i=1;i<=n;i++){
				//cout<<lower_bound(c+1,c+s+1,i)-c<<endl;
				if(c[lower_bound(c+1,c+s+1,i)-c]>i){
					for(int j=1;j<=maxn;j++)b[i][j]=0;
				}
			}
		    maxn--;
		    ds();
		    //cout<<2;
	}else{
		for(int i=1;i<=n;i++){
			if(b[i][maxnn]!=0){
				
			}
		}
	}
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
		int anso=1;
		while(a[i]>0){
			if(a[i]%2==1)b[i][anso]=1;
			a[i]/=2;
			//cout<<b[i][anso]<<" ";
			anso++;
		}
		//cout<<endl;
	}
	//for(int i=1;i<=n;i++){
	//for(int j=1;j<=maxn;j++)cout<<b[i][j]<<" ";
	//cout<<endl;
	//}
	for(int i=1;i<=31;i++){
		for(int j=1;j<=n;j++){
			if(b[j][i]==1)maxn=max(maxn,j);
		}
	}
	maxnn=maxn;
	//for(int i=1;i<=n;i++){
	//for(int j=1;j<=maxn;j++)cout<<b[i][j]<<" ";
	//cout<<endl;
	//}
	//cout<<maxn<<endl;
	ds();
	cout<<ans;
}
