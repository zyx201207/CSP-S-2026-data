#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int l1;
	int n;
	cin>>n;
	s+=" "; 
	long long sum=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int k=1;k<=a;k++){
			s+=c;
		}
		//cout<<"s:"<<s<<" sum:"<<sum<<endl;
		sum+=1LL*a;
	}
	if(sum%2==0){
		l1=sum/(1LL*2);
	}
	else{
		l1=sum/(1LL*2)+1LL;
	}
	//cout<<"l1:"<<l1<<endl;
	long long ans=0;
	for(int i=l1;i<=sum;i++){
		if(i-(2*(i-l1)+1)==0) 
		if(sum%2==0&&s[i-(2*(i-l1)+1)]!=s[i]){
			ans++;
			//cout<<"way1exp:"<<i-(2*(i-l1)+1) << " ";
		}if(sum%2!=0&&s[i-(2*(i-l1))]!=s[i]){
			ans++;
			//cout<<"way2exp:"<<i-(2*(i-l1)+1) << " ";
		}
	}
	cout<<ans;
}
/*
3
2 a
2 b
1 c
s2s2:::::===
2
2 a
3 a

*/
