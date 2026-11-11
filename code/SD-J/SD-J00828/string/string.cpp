#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int g;//geshu
	char c;
};
node a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].g>>a[i].c;
	}
	int ans=0;
	for(int i=1,j=n;i<j&&i<=n&&j>=1;){
		if(a[i].c==a[j].c){
			if(a[i].g>a[j].g){
				a[i].g-=a[j].g;
				j--;
			}else if(a[i].g<a[j].g){
				a[j].g-=a[i].g;
				i++;	
			}else{
				i++;
				j--;
			}
		}else{
			if(a[i].g>a[j].g){
				ans+=a[j].g;
				a[i].g-=a[j].g;
				j--;
			}else if(a[i].g<a[j].g){
				ans+=a[i].g;
				a[j].g-=a[i].g;
				i++;
			}else{
				ans+=a[i].g;
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
3
3 a
6 b
1 c
*/
