#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	if(m==1) cout<<1;
	else if(m==2){
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='1') {
				cout<<i+1<<" ";
				break;
			}
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='2') {
				cout<<i+1<<" ";
				break;
			}
		}
	}
	else if(m==3){
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='1') {
				cout<<i+1<<" ";
				break;
			}
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='2') {
				cout<<i+1<<" ";
				break;
			}
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='3') {
				cout<<i+1<<" ";
				break;
			}
		}
	}
	else if(m==4){
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='1') {
				cout<<i+1<<" ";
				break;
			}
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='2') {
				cout<<i+1<<" ";
				break;
			}
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='3') {
				cout<<i+1<<" ";
				break;
			}
		}
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='4') {
				cout<<i+1<<" ";
				break;
			}
		}
	}
	return 0;
}
