#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t[N][35],r[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long int a[35],b,c,d,e=0,x=0,y=0,s=0,h=0;
	cin>>b>>c;
	for(int i=0;i<b;i++){
		cin>>d;
		r[i]=d;
		h=max(h,d);
	}
	int q=0;
	while(h!=0){
		h/=2;
		q++;
	}
	e=q;
	for(int i=0;i<b;i++){
		q=0;
		while(r[i]!=0){
			t[i][q]=r[i]%2;
			r[i]/=2;
			q++;
		}
		if(q<e){
			for(int j=q;j<e;j++){
				t[i][j]=0;
			}
		}
	}
	e--;
	for(int i=e;i>=0;i--){
		for(int j=0;j<b;j++){
			if(t[j][i]==1){
				if(y==0){
					x++;
				}else if(t[j][y]==1){
					x++;
				}
			}
		}
		if(x>=c){
			a[i]=1;
			if(y==0){
				y=i;
			}
		}else{
			a[i]=0;
		}
		x=0;
	}
	for(int i=0;i<=e;i++){
		if(a[i]==1){
			s+=pow(2,i);
		}
	}
	cout<<s;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
