#include<bits/stdc++.h>
using namespace std;
//删除freopen注释!!!
//测试输出删除！！
long long n;
long long a[200005];
char k[200005];
long long cnt;//s的长度 
long long ans;//修改次数 
string s;//拼接 超时 
string ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>k[i];
		cnt+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		if(k[1]==k[2]){
			cout<<0;
			return 0;
		}else if(k[1]!=k[2]){
			cout<<min(a[1],a[2]);
			return 0;
		}
	}else if(n>=3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=k[i];
			}
		}
//		for(int i=0;i<s.size();i++){
//			cout<<s[i];
//		}
//		cout<<endl;
		long long sum=s.size();
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[sum+1-i]){
				ans++;
			//	cout<<s[i]<<" "<<s[1+sum-i]<<endl ;
			}
		}
		cout<<ans;
		}
		/*
		long long i=1,w=n;
		for(i;;){
			if(k[i]!=k[w]){
				if(a[i]<a[w]){
					ans=ans+a[i];
					a[w]=a[w]-a[i];
				//	cout<<"1\n"; 
					i++;
				}else if(a[i]>a[w]){
					ans=ans+a[w];
					a[i]=a[i]-a[w];
					w--; 
				//	cout<<"2\n";
				}else if(a[i]==a[w]){
					ans+=a[i];
					i++;
					w--;
					//cout<<"3\n";
				}
			}else if(k[i]==k[w]){
				i++;
				w--;
			}
			if(i=w-1){
				if(k[i]==k[w]){
					cout<<ans;
					return 0;
				}else {
					ans+=min(a[i],a[w]);
					cout<<ans;
					return 0; 
				}
			}*/
				
	//	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c
2

2
2 a
3 a
0
2
10 a
10 b
10
1 a
1 b
1 c
1 d
1 e
1 e
1 f
1 k
1 f
1 w
*/
