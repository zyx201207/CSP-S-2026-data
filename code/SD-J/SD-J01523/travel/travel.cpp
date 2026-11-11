#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	string s1,s2;
	ll c1,c2;
	cin>>c1>>s1>>c2>>s2;
	//cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2;
	if(c1!=c2){
		cout<<"0000";return 0;
	}else{
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			ll t1,t2;
			if(s1[2]=='D'||s1[2]=='E'){
				t1=1;
			}else{
				t1=2;
			}if(s2[2]=='D'||s2[2]=='E'){
				t2=1;
			}else{
				t2=2;
			}
			if(t1!=t2){
				cout<<"00";return 0;
			}else{
				cout<<1;
				if(abs(s2[2]-s1[2])==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}else{
			cout<<"000"; return 0;
		}
	}
	return 0;
}
//   02 02C 02 02D
//   02 02C 02 02E
//   02 02C 02 03D
//   02 02A 02 02D
//   16 14A 16 14B



// 8:49


//froepen
// tarvel
// .ans
// bits\stdc++.h
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
// slf xch0122 djr ak ioi
