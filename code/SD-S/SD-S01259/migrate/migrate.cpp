#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[2000010];
int g[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,t;
	int n;
	LL m;
	cin>>c>>t;
	if(c>10&&c<13){
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			if(n==1){
				cout<<"0\n";
				continue;
			}
			LL res=m/(a[2]-a[1])-1;
			if(res<=0){
				cout<<"0\n";
				continue;
			}
			if(res*2+1<=n){
				cout<<(n-res*2-1)<<'\n';
			}else cout<<"0\n";
		}
	}else {
		vector<int> ve1,ve2;
		while(t--){
			cin>>n>>m;
			for(int i=1;i<=n;i++)cin>>a[i];
			for(int i=2;i<=n;i++)a[i]-=a[1];
			a[1]=0;
			for(int i=1,k;i<=n;i++){
				k=upper_bound(a+1,a+n+1,a[i]+m)-a;
				g[i]=k-(a[i]+m<=a[n]);
			}
			LL cnt=0,res;
			int fg;
			for(int i=1;i<=n;i++){
				for(int j=i+2;j<=n;j++){
					fg=0,res=0;
					while(ve1.size())ve1.pop_back();
					while(ve2.size())ve2.pop_back();
					for(int k=i,l;k<j;k=l){
						ve1.push_back(k);
						l=g[k];
						if(l==k){
							fg=-1;
							break;
						}
					}
					if(fg==-1)continue;
					ve1.push_back(j);
					for(int k=j,l;k>i;){
						ve2.push_back(k);
						l=lower_bound(g+1,g+n+1,k)-g;
						if(l==k){
							fg=-1;
							break;
						}
						k=l;
					}
					if(fg==-1)continue;
					ve2.push_back(i);
					if(ve1.size()!=ve2.size())continue;
//					cout<<i<<' '<<j<<endl;
//					for(int k=0;k<ve1.size();k++)cout<<ve1[k]<<'&'<<ve2[ve1.size()-k-1]<<endl;
					for(int k=0;k<ve1.size();k++){
						if(ve1[k]!=ve2[ve1.size()-k-1]){
							res+=abs(ve1[k]-ve2[ve1.size()-k-1]);
							fg++;
//							cout<<k<<endl;
						}
					}
//					if(fg==1&&res==1)cout<<i<<' '<<j<<endl;
					cnt+=(fg==1&&res==1);
				}
			}
			cout<<cnt<<'\n';
		}
	}
	return 0;
}

