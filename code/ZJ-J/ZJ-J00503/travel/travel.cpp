#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n1,n2;
	string s1,s2;
	cin>>n1>>s1>>n2>>s2;
	if(n1!=n2){
		cout<<"0000";
	}
	else if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		cout<<"1000";
	}
	else{
		int p=s1[2],q=s2[2];
		if(p>q){
			swap(p,q);
		}
		if(p<=67){
			if(q>67){
				cout<<"1100";
			}
			else if(q==p+1){
				cout<<"1111";
			}
			else{
				cout<<"1110";
			}
		}
		else{
			cout<<"1111";
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//while (1){
		solve();
	//}
	return 0;
}
