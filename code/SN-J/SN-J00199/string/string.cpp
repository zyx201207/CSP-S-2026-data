#include <bits/stdc++.h>

typedef long long ll;

struct node{
	ll numb;
	char now;
}a[200010];

int n;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::cin>>n;
	for(int i=1;i<=n;i++)
		std::cin>>a[i].numb>>a[i].now;
	int right=n;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(right<=i)
			break;
		while(right>i){
			if(a[right].now==a[i].now){
				if(a[right].numb>=a[i].numb){
					a[right].numb-=a[i].numb;
					break;
				}
				else{
					a[i].numb-=a[right].numb;
					right--;
				}
			}
			else{
				if(a[right].numb>=a[i].numb){
					a[right].numb-=a[i].numb;
					ans+=a[i].numb;
					break;
				}
				else{
					a[i].numb-=a[right].numb;
					ans+=a[right].numb;
					right--;
				}
			}
		}
	}
	std::cout<<ans<<"\n";
	return 0;
}
