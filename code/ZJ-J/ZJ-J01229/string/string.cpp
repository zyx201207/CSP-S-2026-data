#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
struct node{
	int g;
	char c;
}num[N];
int ans=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i].g>>num[i].c;
	}
	int l=1,r=n;
	while(l<r){
		if(num[l].c==num[r].c){
			if(num[l].g<num[r].g){
				num[r].g-=num[l].g;
				l++;
			}
			else if(num[l].g>num[r].g){
				num[l].g-=num[r].g;
				r--;
			}
			else{
				l++;
				r--;
			}
		}
		else{
			if(num[l].g<num[r].g){
				ans+=num[l].g;
				num[r].g-=num[l].g;
				l++;
			}
			else if(num[l].g>num[r].g){
				ans+=num[r].g;
				num[l].g-=num[r].g;
				r--;
			}
			else{
				ans+=num[r].g;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}