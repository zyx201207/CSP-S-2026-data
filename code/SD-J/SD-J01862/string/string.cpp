#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+5;
int n;
ll len,ans;
struct node{
	int ge;
	string zi;
};
node a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].ge>>a[i].zi;
		len+=a[i].ge;
	}
	for(ll i=1,j=len;i<=j;){
		if(a[i].zi!=a[j].zi){
			if(a[i].ge==a[j].ge){
				ans+=a[i].ge;
				i++;
				j--;
			}
			else if(a[i].ge<a[j].ge){
				ans+=a[i].ge;
				a[j].ge-=a[i].ge;
				i++;
				continue;
			}
			else{
				ans+=a[j].ge;
				a[i].ge-=a[j].ge;
				j--;
				continue;
			}
		}
		else{
			if(a[i].ge==a[j].ge){
				i++;
				j--;
				continue;
			}
			else if(a[i].ge<a[j].ge){
				a[j].ge-=a[i].ge;
				i++;
				continue;
			}
			else{
				a[i].ge-=a[j].ge;
				j--;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
