#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>c2>>s1>>s2;
	int cnt=4;
	if(c1==s1){
		cout<<1;
		cnt--;
		if(c2[0]+c2[1]==s2[0]+s2[1]){
			cout<<1;
			cnt--;
			if(c2[2]<='C'&&s2[2]<='C' || c2[2]>='D'&&s2[2]>='D'){
				cout<<1;
				cnt--;
				if(c2[2]+1==s2[2]||c2[2]-1==s2[2]){
					cout<<1;
					cnt--;
				}
			}
		}
	}
	for(int i=0;i<cnt;i++){
		cout<<0;
	}
	return 0;
}
