#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int b;
	int i=0;
	while(1){
		if(!m)break;
		if(a[i]==a[i+1]&&m){
			i++;
			continue;
		}
		if(a[i]<a[i+1]&&m){

			a[i]++;
			m--;
			sort(a,a+n);
			i=0;
			continue;
		}
		if(a[i]>a[i+1]&&m){
			i=0;
			a[i]++;
		}
	}
	sort(a,a+n);
	int ans=0;
	for(int i=0;i<n;i++){
		if(a[i]==a[0])ans++;
	}
	cout<<ans;
	return 0;
}
/*
¨¬ao???¡ã?
?¡ê¨ª??¨¹¦Ì?30-40¡¤?
QwQ
*/

