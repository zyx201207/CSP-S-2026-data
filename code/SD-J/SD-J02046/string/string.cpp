#include<bits/stdc++.h>
using namespace std;
int n;
string s="";
int a[10005],b[10005];
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n;
	int x;
	int ans=0,cnt=1,num=0;
	while(n--){
		int a;string b;
		cin>>a>>b;
		if(a==1){
			x=b[0];
			cnt=0;
		}
		while(a--){
			s+=b;
		} 
	}	int l=s.size();
	 if(cnt==0){
	 	for(int i=1;i<=l;i++){
	 		if(s[i]==x){
	 			swap(s[i],s[i/2+1]);
	 			num++;
	 			break;
			 }
		 }
	 }
	int f=1;
	for(int i=0;i<l/2+1;i++){
		if(s[i]!=s[l-1-i]){
			f=0;
		}
	}
	if(f==1){
		cout<<0;
		return 0;
	}
		for(int i=0;i<l/2;i++){
			a[s[i]-'0'-96]++;
		} 
		for(int i=l/2;i<l;i++){
			b[s[i]-'0'-96]++;
		}
//	if(l%2==0)
//	{
		for(int i=0;i<l/2;i++){
			if(s[i]!=s[l+1-i]){
				if(a[s[i]]--<b[s[i]]){	
					for(int j=l/2;j<l;j++){
						if(s[j]==s[i]){
							swap(s[i],s[j]);
							num++;
						}
					}
				}
				else{
					for(int j=i+1;j<l/2;j++){
						if(s[j]==s[i]){
							swap(s[i],s[j]);
							num++;
						}
					}
				}
			}
		}
		cout<<s;
	
	cout<<num;
	return 0;

}
