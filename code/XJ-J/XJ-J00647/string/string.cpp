#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,mid=0,ans=0;
	cin>>n;
	string a="";
	for (int i=1;i<=n;i++){
		int x;
		string s;
		cin>>x>>s;
		for (int j=1;j<=x;j++){
			a+=s;
		}
	}
	string a2=a;
	reverse(a2.begin(),a2.end());
	if(a==a2){
		cout<<0;
		return 0;
	}
	int len=a.size();
	if(len%2==1){
		int l=0,r=len;
		for (int i=0;i<len;i++){
			l++;
			r--;
			if(l-r==1){
				mid=l;
			}
			
		}
		int x=mid,y=mid;
		for (int i=0;i<len;i++){
			x--;
			y++;
			if(x==0&&r==len){
				break;
			}
			
			if(a[x]!=a[y]){
				ans++; 
			}
			
		}
		cout<<ans/2;
		return 0;
	}else{
		int l=0,r=len;
		for (int i=0;i<len;i++){
			l++;
			r--;
			if(l==r){
				mid=l;
			}
			
		}
		int x=mid,y=mid;
		for (int i=0;i<len;i++){
			x--;
			y++;
			if(x==0&&r==len){
				break;
			}
			
			if(a[x]!=a[y]){
				ans++;
			}
			
		}
		cout<<ans/2;
		return 0;
	}                                                
	return 0;
}