#include<iostream>
using namespace std;
#define int long long
int a[500005];
int cun[300005];
int n,m;
void zhaodi(int st){
	int x=a[st];
	cun[x]++;
	if(st>=n-1) return;
	int f=1;
	for(int i=n-1;i>st;i--){
		if(a[i]==a[st]){
			f=0;
			zhaodi(i+1);
			break;
		}
	}
	if(f==1){
		zhaodi(st+1);
	}
	return;
};
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		zhaodi(i);
	}
	for(int i=1;i<=m;i++){
		cout<<cun[i]<<" ";
	}
	return 0;
}
