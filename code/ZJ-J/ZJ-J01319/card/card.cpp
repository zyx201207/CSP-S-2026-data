#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
bool del[N],ok[N];
int a[N],ans[N];
bool ipt=true;
int one=0,two=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==1) one++;
		if(a[i]==2) two++;
		if(a[i-1]>a[i])
			ipt=false;
	}
	if(ipt==true){
		for(int i=n;i>=1;i--)
			ans[a[i]]=max(ans[a[i]],i);
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
		return 0;
	}
	if(m==2){
		if(a[n]==1){
			if(one==1 and two==n-1){
				cout<<n<<' '<<n-1<<'\n';
			}else if(a[1]==2 and a[n-1]==2){
				cout<<n<<' '<<1<<'\n';
			}else cout<<n<<' '<<0<<'\n';
		}
		else if(a[n]==2){
			if(one==n-1 and two==1){
				cout<<n-1<<' '<<n<<'\n';
			}else if(a[1]==2 and a[n-1]==2){
				cout<<1<<' '<<n<<'\n';
			}else cout<<0<<' '<<n<<'\n';			
		}
		return 0;
	}
	for(int t=1;t<=n;t++){
		for(int i=1;i<=n;i++)
			del[i]=false,ok[i]=false;
		for(int j=t;j<=n;j++){
			for(int k=t;k<=j-1;k++){
				if(del[k]==false && a[k]==a[j]){
					for(int v=k;v<=j-1;v++)
						del[v]=true;
					break;
				}
			}
		}
		for(int i=t;i<=n;i++){
			if(del[i]==false) 
				ok[a[i]]=true;
		}
		for(int i=1;i<=m;i++)
			if(ok[i]) ans[i]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';		
}