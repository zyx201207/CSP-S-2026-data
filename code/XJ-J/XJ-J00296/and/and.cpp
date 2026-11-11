# include <bits/stdC++.h>
using namespace std;
int N=1005;
int main (){
	int a=0,b=0,c=0,d=0;
	int num[N],ans[N];
	cin>>a>>b;
	for(int i=0;i<=1005;i++){
		ans[i]=0;
	}
	for(int i=0;i<=1005;i++){
		num[i]=0;
	}
	for (int i=1;i<=a;i++){
		cin>>num[i];
	}
	for (int i=1;i<=a;i++){
		for(int j=i+1;j<=a-1;j++){
			if(j>a){
				continue;
			}
			ans[c]=min(num[i],num[j]);
			c++;
		}
	}
	for(int i=0;i<=1005;i++){
		
		if(ans[i]<ans[i+1]){
			d=ans[i+1];
		}
	}
	
	cout<<d;
	return 0;
}