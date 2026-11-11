#include<bits/stdc++.h>
using namespace std;
const long long N=10005;//long long=躲不开的作业 
int n,a[N],ans=0,len;
string c[N];
bool tepan(string c[N]){
	for(int i=0;i<n;i++) {
		if (c[i]==c[i+1]) return false;
		continue;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	for(int i=0;i<n;i++) ans=a[i]+ans;
	for(int i=0;i<n;i++){
		len=0;
		for(int i=0;i<n;i++){
			if (a[i]%2==0){
				if (c[i]==c[i+1]) continue;
				len++;
			}
		}
	}
	cout<<len;
	return 0;
}
/*

*/
