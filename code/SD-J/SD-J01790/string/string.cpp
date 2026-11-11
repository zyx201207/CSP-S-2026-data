#include<iostream>
#include<cstring>
#define int long long
using namespace std;
string s1,s2;
string c1,c2;
struct word1{
	int yui;
	char iuy;
}str[200007];
word1 lfet1[200007];
word1 rghit1[200007];
int flag[26];
int all;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		all+=x;
		str[i]=(word1){x,c};
//		cout<<str[i].yui<<endl;
	}
//	cout<<all<<endl;
	int mid=all/2; 
	bool kild=(all%2==0)?1:0;
	int tot=0,kiloo;
	for(int i=1;i<=n;i++){
		int c1=str[i].yui;
		char x1=str[i].iuy;
		tot+=c1;
		if(tot>mid){
			int ch=tot-mid;
			kiloo=ch;
			lfet1[i]=(word1){c1-ch,x1};
//			cout<<"left    "<<lfet1[i].yui<<endl;
			break;
		}
		lfet1[i]=(word1){c1,x1};
//		cout<<"left    "<<lfet1[i].yui<<endl;
	}
	tot=0;
	for(int i=n;i>=1;i--){
		int c1=str[i].yui;
		char x1=str[i].iuy;
		tot+=c1;
		if(tot>mid){
			int ch=tot-mid;
			if(!kild)
				rghit1[i]=(word1){kiloo-1,x1};
			else
			    rghit1[i]=(word1){kiloo,x1};
//			cout<<"right    "<<rghit1[i].yui<<endl;
			break;
		}
		rghit1[i]=(word1){c1,x1};
//		cout<<"right    "<<rghit1[i].yui<<endl;
	}
	int i=1,j=n;
	int ans=0,ans2=0;
	while(i<j){
		if(lfet1[i].iuy!=rghit1[j].iuy){
//				cout<<"ans1    "<<rghit[j].
			if(lfet1[i].yui>rghit1[j].yui){
				ans+=rghit1[j].yui;
				lfet1[i].yui-=rghit1[j].yui;
				j--;
//				cout<<1<<endl;
			}
			else if(lfet1[i].yui<rghit1[j].yui){
				ans+=lfet1[i].yui;
				rghit1[j].yui-=lfet1[i].yui;
				i++;
//				cout<<2<<endl;
			}
			else{
				ans+=lfet1[i].yui;
				i++;j--;
//				cout<<3<<endl;
			}
//			cout<<ans<<endl;
		}
		else{
			if(lfet1[i].yui>rghit1[j].yui){
				lfet1[i].yui-=rghit1[j].yui;
				j--;
			}
			else if(lfet1[i].yui<rghit1[j].yui){
				rghit1[j].yui-=lfet1[i].yui;
				i++;
			}
			else{
				i++;
				j--;
			}
		}
	}
	cout<<ans<<endl;
}
