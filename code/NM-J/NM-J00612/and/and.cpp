#include<bits/stdc++.h>
using namespace std;
long long x[200010];
string y[200010],z[200010];
int asd(string x,string y){
	long long s=0,b=1;
	int a=max(x.size(),y.size());
//	cout<<a;
	for(int i=0;i<a;i++){
		if(x[i]==y[i]){
			s+=b;//cout<<s<<" ";
		}else{
			s+=0;
		}
		b*=2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>x[i];
	}
	for(int i=1;i<=a;i++){
		long long c;
		c=x[i];
		while(c>0){
			if(c%2!=0){
				   z[i]+='1';
			}else{
				   z[i]+='0';
			}
			c/=2;
		}
//	cout<<z[i]<<" ";
	}
//	cout<<endl;
	for(int i=1;i<=a;i++){
		int v=z[i].size();
		for(int j=v-1;j>=0;j--){
			y[i]+=z[i][j];
		}
//		cout<<y[i]<<" ";
	}
	int num=0;
//	cout<<endl;
	for(int i=1;i<=a;i++){
		for(int j=i+1;j<=a;j++){
	//		cout<<i<<" "<<j<<" "; 
			num=max(asd(y[i],y[j]),num);
		}
		//cout<<endl;
	}
	cout<<num;
	return 0;
}
