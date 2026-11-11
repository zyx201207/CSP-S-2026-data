#include<bits/stdc++.h>
#define I_don_t_want_to_AFO int main()
#define I_want_to_study_OI_forever return 0;
using namespace std;
string s1,c1,s2,c2;
string a,b;
void solve(){
	cin>>s1>>c1>>s2>>c2;
	for(int i=0;i<=1;i++){
		a+=c1[i];
		b+=c2[i];
	}
//	cout<<a<<" "<<b<<" ";
	if(s1==s2){
		if(a==b){
			char p=c1[2],q=c2[2];
			if(p>q)swap(q,p);
//			cout<<p<<" "<<q;
			if((p=='A'&&q=='B')||(p=='A'&&q=='C')||(p=='B'&&q=='C')||(p=='D'&&q=='F')){
				if((p=='A'&&q=='B')||(p=='B'&&q=='C')||(p=='D'&&q=='F')){
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
}
I_don_t_want_to_AFO{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--){
		solve();
	}
	I_want_to_study_OI_forever
}
