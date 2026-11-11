#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	int cnt=m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}

	for(int i=1;i<=n;i++){
		if(a[i+1]!=0){
			if(a[i]<a[i+1]){
				break;
			}else{
				int p=0;
				p=a[i];
				a[i]=a[i+1];
				a[i+1]=p;	
		    }
		}
	}
//	for(int i=1;i<=n;i++){
//		cout << a[i];
//	}

	int ans=0;
	for(int i=1;i<=n;i++){
		int num = a[i+1]-a[i];
		if(num<m || num==m){
			a[i]+=num;
			m-=num;
			num=a[i+1]-a[i];
		}
		if(m==0){
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
	}
	ans+=1;
	cout <<ans <<"\n";
	
	return 0;
} 
