#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int x,y;
string a,b;
bool check1(){
	return x==y;
}
bool check2(){
	int t1=10*(a[0]-'0')+(a[1]-'0');
	int t2=10*(b[0]-'0')+(b[1]-'0');
	return t1==t2;
}
bool check3(){
	int cha=a[2]-'A';
	int chb=b[2]-'A';
	if(cha>chb)swap(cha,chb);
	if(0<=cha&&chb<=2)return true;
	else if(3<=cha&&chb<=5)return true;
	else return false;
}
bool check4(){
	int cha=a[2]-'A';
	int chb=b[2]-'A';
	if(cha>chb)swap(cha,chb);
	if((cha==0&&chb==1)||(cha==1&&chb==2)||(cha==3&&chb==5)){
		return true;
	} else return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>x>>a>>y>>b;
	if(check1()){
		cout<<"1";
		if(check2()){
			cout<<"1";
			if(check3()){
				cout<<"1";
				if(check4()){
					cout<<"1";
				} else {
					cout<<"0";
				}
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}