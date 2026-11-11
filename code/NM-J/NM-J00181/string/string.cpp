#include<bits/stdc++.h>
using namespace std;
int a[100000000];
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int q;
	cin>>q;
	for(int i=1; i<=q; i++) {
		cin>>a[i]>>s[i];
	}
	string zfc1;
	for(int i=1; i<=q; i++) {
		for(int j=1; j<=a[i]; j++) {
			zfc1+=s[i];
		}
	}
	int res=0;
	int res2=0;
	int len=zfc1.size();
	for(int i=1; i<=zfc1.size(); i++) {
			res=0;
		for(int ji=97; ji<=122; ji++) {
			int l=1,r=zfc1.size();
			zfc1[i]=(char)ji;
		
				while(zfc[l]!=zfc[r])
				{
					l++;
					r--;
					res2++;
				}
			if(zfc[i]=zfc[len-i]);
				{
					res++;
				}
			
			}
				
		}
			cout<<res<<endl<<res2;
return 0;
	}


