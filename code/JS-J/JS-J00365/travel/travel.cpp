#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=1e6+34;

int site[34][34];
int a,b;
char ca,cb;
int ax,ay,bx,by;

int main(){
	freopen("travel.in","r",stdin);	
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a>>ax>>ca>>b>>bx>>cb;
	ay=ca-'A';
	by=cb-'A';
	//cout<<a<<" "<<ax<<" "<<ay<<endl;
	//cout<<b<<" "<<bx<<" "<<by<<endl;
	
	
	if(a==b)cout<<1;
	else cout<<0;
	if(a==b&&ax==bx)cout<<1;
	else cout<<0;
	if(a==b&&ax==bx&&((ay<=2&&by<=2)||(ay>=3&&by>=3)))cout<<1;
	else cout<<0;
	if(a==b&&ax==bx&& ((ay<=2&&by<=2)||(ay>=3&&by>=3)) && (( (ay+1)==by )||( (by+1)==ay )) )cout<<1;
	else cout<<0;
	
	return 0;
}
