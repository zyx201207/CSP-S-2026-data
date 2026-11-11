#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+10;
ll n,m,a[N],b[N];
ll maxx = -1;
bool flag = true;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	if(n<=5000)
	{
		for(ll i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(ll i=n;i>=1;i--){
			ll cnt=1, fm=m;
			for(ll j=i-1;j>=1;j--){
				ll k=a[i]-a[j];
				//cout<<a[i]<<" "<<a[j]<<" "<<k<<endl;
				if(fm>=k){fm-=k;cnt++;
				}
				else{break;}
			}
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
	}
	else{
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if(a[i] != i)
			{
				flag=false;
			}
		}
		if(flag){
			int zn=1;
			while(1){
				if(m>=zn){
					m-=zn;
					zn++;
				}
				else
				{
					cout << zn;
					break;
				}
			} 
		}
		else{
			sort(a+1,a+n+1);
			bool tk = true;
			for(int i = 2;i<=n;i++){
				if(a[i]!=a[i-1]){
					tk=false;
					break;
				}
			}
			if(tk){
				int k = a[4]-a[3],zn=k;
				while(1){
					if(m>=zn){
						m-=zn;
						zn += k;
					}
					else
					{
						cout << zn/k;
						break;
					}
				}
			}
			else{
				int sum=0, num=n-1;
				for(int i=1;i<n;i++){
					b[i]=a[i+1]-a[i];
					sum+=b[i]*i;
				}
				for(int i = n-1; i>=1;i--){
					if(sum > m){
						//cout << b[i]<<" ";
						sum-=num*b[i];
						//cout<<sum<<" ";
						num--;
					}
					else
					{
						cout<<num+1;
						break;
					}
				}
			}
		}
	} 
	return 0;
 } 