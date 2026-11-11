#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,l=1,tl,tr;
ll r,ans;
string s;
struct st{
	char ch;
	ll tn;
}a[200005];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].tn>>a[i].ch;
	}
	r=n;
	while(l<r){
//		cout<<l<<" "<<r<<" "<<ans<<endl;
		if(a[l].ch!=a[r].ch){
			ans+=min(a[l].tn,a[r].tn);
			if(a[l].tn==a[r].tn){
				l++,r--;
			}
			else{
				if(a[l].tn>a[r].tn){
					a[l].tn-=a[r].tn;
					r--;
				}
				else{
					a[r].tn-=a[l].tn;
					l++;
				}
			}
		}
		else{
			if(a[l].tn==a[r].tn){
				l++,r--;
			}
			else{
				if(a[l].tn>a[r].tn){
					a[l].tn-=a[r].tn;
					r--;
				}
				else{
					a[r].tn-=a[l].tn;
					l++;
				}
			}
		}
	}	
	cout<<ans;
	return 0;
}
/*
4
4 a
2 b
2 a
2 b

7
4 a
4 b
1 a
1 b
1 a
1 b
1 a
*/

