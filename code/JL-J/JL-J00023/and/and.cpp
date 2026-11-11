#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	int a,b;
	cin>>a>>b;
	long long ln[200000005];
	for (int i = 0; i<a;i++){
		cin>>ln[i];
		}
	int ans = 0;
	for (int i = 0;i < a-1;i++){
		if (ln[i] == ln[i+1] && ln[i] > ans){
			ans = ln[i];
			
			}
}
	cout<<ans;



}
