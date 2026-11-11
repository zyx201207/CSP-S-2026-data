#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int ch,z;
	char cz;
};
node a,b;
inline bool pa(char l,char c,char r){
	return (l<=c&&c<=r);
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>a.ch>>a.z>>a.cz>>b.ch>>b.z>>b.cz;
	if(a.ch==b.ch){
		if(a.z==b.z){
			if(pa('A',a.cz,'C')&&pa('A',b.cz,'C')){
				if(abs(a.cz-b.cz)==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else if((a.cz=='D'||a.cz=='F')&&(b.cz=='D'||b.cz=='F')){
				if((a.cz=='D'&&b.cz=='F')||(a.cz=='F'&&b.cz=='D')){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
