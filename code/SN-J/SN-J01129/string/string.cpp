#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
long long sum;
int s;
string str1,str2,str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;	
	for(int i=1;i<=n;i++){
		cin>>b[i]>>str[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=b[i];j++){
			str1+=str[i];
			str2+=str[i];
		}
	}
	reverse(str1.begin(),str1.end());
	cout<<str1<<' '<<str2<<endl;
	for(int i=0;i<=str1.size();i++){
		if(str1[i]!=str2[i]) sum++;
	}
	sum/=2;
//	if(n%2==0){
//		for(int i=1;i<=n/2;i++){
//			a[i]=b[i];
//			str1[i]=str[i];		
//		}
//		for(int i=n/2+1;i<=n;i++){
//			a[i]=b[i];
//			str2[i-n/2]=str[i];		
//		}
//		for(int i=1;i<=n/2;i++){
//			if(str1[i]!=str2[i]) sum+=a[i];
//		}
//	}else{
//		char ch;
//		for(int i=1;i<=n/2;i++){
//			cin>>a[i]>>str1[i];		
//		}
//		cin>>a[n/2+1]>>ch;
//		for(int i=n/2+2;i<=n;i++){
//			cin>>a[i]>>str2[i-(n/2+2)];		
//		}
//		for(int i=1;i<=n/2;i++){
//			if(str1[i]!=str2[i]) sum+=a[i];
//		}
//	}
//	cout<<sum;
	cout<<sum;
	return 0;
}
/*

2
2 a
3 a

*/
