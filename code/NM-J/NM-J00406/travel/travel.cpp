#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		string r1(s1.substr(0,2)),n1(s1.substr(2)),r2(s2.substr(0,2)),n2(s2.substr(2));
		if(r1!=r2){
			cout<<"000";
		}else{
			cout<<"1";
			int si1,si2;
			if(n1[0]<='C')si1=0;
			else si1=1;
			if(n2[0]<='C')si2=0;
			else si2=1;
			if(si1!=si2){
				cout<<"00";
			}else{
				cout<<"1";
				bool flag=si1;
				if(si1==0&&abs(n1[0]-n2[0])==1)flag=true;
				if(flag){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
		}
	}
	cout<<endl;
	return 0;
}
/*
 * hello,i am @gjr19509 on luogu
 * 
 * if you see me please put me on the exhibition of strange actions!!!
 * 
 * as a 9th grader, i will probably AFO if i cant go into Ordos No.1 high school
 * 
 * it's 11:17 now
 * 
 * i think T1,2 AC, T3 maybe 50, T4 0
 * 
 * should i take a speech ofor my AFO here?
 * 
 * but i dont know how to :)
 * 
 * qwq
 * 
 * Have a good day!
 */

// Never gonna give you up
// freopen("travel.in","w",stdin);
// freopen("travel.out","r",stdout);
// int mian(){
