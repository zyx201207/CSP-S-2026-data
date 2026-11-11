#include<iostream>
using namespace std;
string str="";
int ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int i=1;i<=x;i++) str+=y;
	}
	int s=str.size();
	if(s%2==1){
		int mid=s/2+1;
		int l=mid-1,r=mid+1;
		while(l>=1&&r<=s){
			if(str[l]!=str[r]) ans++;
			l--;
			r++;
		}
	}else{
		int mid=s/2;
		int l=mid,r=mid+1;
		while(l>=1&&r<=n){
			if(str[l]!=str[r]) ans++;
			l--;
			r++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout); 	
	return 0;
}
