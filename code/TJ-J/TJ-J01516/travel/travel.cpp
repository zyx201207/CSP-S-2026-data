#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char c11,c12,s11,s12,s13;
	cin>>c11>>c12>>s11>>s12>>s13;
	char c21,c22,s21,s22,s23;
	cin>>c21>>c22>>s21>>s22>>s23;	
	if(c11==c21&&c12==c22) cout<<1;
	if(c11!=c21||c12!=c22) cout<<0;
	bool flag=true;
	if(c11==c21&&c12==c22&&s11==s21&&s12==s22) cout<<1;
	if(s11!=s21||s12!=s22){
		cout<<0;
		flag=false;
    }
    if(c11!=c21||c12!=c22) cout<<0;
    bool flag1=true,flag2=true;
    if(s13=='A'||s13=='B'||s13=='C') flag1=true;
    if(s13=='D'||s13=='F') flag1=false;
    if(s23=='A'||s23=='B'||s23=='C') flag2=true;
    if(s23=='D'||s23=='F') flag2=false;
	if(flag==false) cout<<0;
	if(flag==true&&flag1!=flag2) cout<<0;
	if(c11!=c21||c12!=c22) cout<<0;
	if(c11==c21&&c12==c22&&flag==true&&flag1==flag2) cout<<1;	
	if(flag1==flag2&&s11==s21&&s12==s22&&s13-('b'-'a')==s23){
		cout<<1;
		return 0;
	}
	if(flag1==flag2&&s11==s21&&s12==s22&&s13+('b'-'a')==s23){
		cout<<1;
		return 0;
	}	
	if(flag1==flag2&&s11==s21&&s12-('b'-'a')==s22&&s13==s23){
		cout<<1;
		return 0;
	}
	if(flag1==flag2&&s11==s21&&s12+('b'-'a')==s22&&s13==s23){
		cout<<1;
		return 0;
	}
	if(flag1==flag2&&s11=='1'&&s12=='0'&&s21=='0'&&s22=='9'&&s13==s23){
		cout<<1;
		return 0;
	}
	if(flag1==flag2&&s11=='0'&&s12=='9'&&s21=='1'&&s22=='0'&&s13==s23){
		cout<<1;
		return 0;
	}
	else cout<<0;
	return 0;
}
