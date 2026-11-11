# include <bits/stdC++.h>
using namespace std;
int N=1005;
int main (){
	int a,b,c,d=1,e=0;
	cin>>a>>b;
	int num[N],desk[N],ans[b];
	for(int i=0;i<a;i++){
		cin>>num[i];
	}
	for(int i=1;i<=a;i++){
		desk[i-1]=num[d-1];
		for(int j=0;j<=a;j++){
		if(num[j]==desk[i-1]){
			e=1;
		}
		
		if(e){
			for(int j=0;j<i-1;j++){
				desk[i]=0;
			}
		}
		}
		d++;
		for(int i=0;i<=a;i++){
			if(desk[i]==d)
			ans[i]++;
		}	
	}
	for(int i=1;i<=d;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}