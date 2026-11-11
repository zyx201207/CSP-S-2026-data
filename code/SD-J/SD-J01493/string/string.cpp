#include<bits/stdc++.h>//使用复原字符串的方法只能拿68分（小概率有n=1可以多拿），推测有不用复原字符串就能做的方法，但我没想出来 
using namespace std;//2st
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string S;
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;	
	}
	for(int i=0;i<n;i++){//get string
		long long x;
		char c;
		cin>>x;
		getchar();
		c=getchar();
//		cout<<"** "<<c<<" **"<<'\n';
		while(x--)S+=c;//this step spends the most time and may have better way
	}
//	cout<<S;
	long long ans=0;
	long long siz=S.size();
	for(long long i=0;i<siz/2;i++){//this is slow too
		if(S[i]!=S[siz-1-i])ans++;
	}
	cout<<ans;
//	cout<<endl;for(int i=0;i<S.size();i++){
//		cout<<S[i];
//	}
	return 0;
} 
/*样例 ,3超时，5爆 

3
2 a
2 b
1 c

2
2 a
3 a 

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
