#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200010];

int s[10];

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	if(n==m){
		long long ans;
		cin>>a[1];
		ans=a[1];
		for(int i=2;i<=n;i++){
			cin>>a[i];
			ans=(ans & a[i]);
		}
		cout<<ans;
	}
	else if(m==1){
		long long mx_num=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mx_num=max(mx_num,(long long)a[i]);
		}
		cout<<mx_num;
	}
	else if(m==2){
		long long mx_num=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long cnt=(a[i] & a[j]);
				mx_num=max(mx_num,cnt);
			}
		}
		cout<<mx_num;
	}
	else if(m==(n-1)){
		long long ans;
		long long mn_num=pow(2,30);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			mn_num=min(mn_num,(long long)a[i]);
		}
		int flag=0;
		if(a[1]!=mn_num){
			ans=a[1];
		}
		else{
			flag=1;
			ans=a[2];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==mn_num && flag==0){
				flag=1;
				continue;
			}
			ans=(ans & a[i]);
		}
		cout<<ans;
	}
	else{
		int flag=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]>=4){
				flag=1;
			}
		}
		if(flag==0){
			for(int i=1;i<=n;i++){
				s[a[i]]++;
			}
			if(s[3]<m){
				if(s[3]+s[2]<m){
					cout<<0;
				}
				else cout<<2;
			}
			else cout<<3;
		}
		else{
			cout<<0;
		}
	}
	return 0;
}
