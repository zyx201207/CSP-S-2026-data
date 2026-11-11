#include <bits/stdc++.h>
using namespace std;
int n,a[1000000];
long long cnt,cnt1;
string s1[200000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int i1=1;
	for(int i=1;i<=n;i++){
		string sp;
		int num;
		cin>>num>>sp;
		if(sp==s1[i1-1]){
			a[i1-1]+=num;
		}
		else{
			a[i1]=num;
			s1[i1]=sp;
			i1++;
		}
		cnt1+=num;
	}
	if(i1<=2){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=i1/2;i++){
		a[i1-i]-=a[i];
		if(a[i1-i]<0){
			a[i1-i-1]+=a[i1-i];
			a[i1-i]=0;
		}
		cnt+=a[i];
		
	}cout<<cnt;
	//if(i1%2==1)cout<<cnt/2;
	//else cout<<cnt/2+1;
	
	
	
	//int l=0,r=s.size()-1,ans=0;
	//while(l<=r){
		//if(s[l]!=s[r]){
			//ans++;
			//l++;
			//r--;
		//}
		//else{
	//		l++;
		//	r--;
		//}
//	}
	
	return 0;
}
