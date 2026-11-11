#include<bits/stdc++.h> 
using namespace std;
long long n;
string f;
struct c1{
	long long sum;
	char c;
}cc[500];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int up=0,up1=0;
	bool oo=true;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>cc[i].sum;
		up1+=cc[i].sum;
		cin>>cc[i].c;
		for(int j=up;j<up1;j++){
			f[j]=cc[i].c;
		}
		up+=cc[i].sum;
		if(i>=1&&cc[i].sum!=cc[i-1].sum){
			oo=false;
		}
	}
	if(oo){
		cout <<0;
		return 0;
	}
	up=up/2;
	int q=0;
	for(int i=0;i<up;i++){	
		if(f[up-i]!=f[up+i]){
			q++;
		}
	}
	cout<<q+1;
	return 0;
}
