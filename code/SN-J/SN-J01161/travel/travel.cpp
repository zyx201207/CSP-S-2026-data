#include<bits/stdc++.h>
using namespace std;
int x1,x2;
string A,B;
char seat[3];
int ans[5];
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.ans12","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>x1>>A>>x2>>B;
	int x=0,y=0;
	for(int i=0;i<=1;i++){
		int w=A[i]-'0';
		x=10*x+w;
		int k=B[i]-'0';
		y=10*y+k;
	}
	if(x1!=x2){
		cout<<"0000"<<"\n";
	}else{
		if(x==y){
			int xx=A[2]-'A'+1;
			int yy=B[2]-'A'+1;
			if(xx>yy){
				swap(xx,yy);
			}
			if((xx<=3&&yy<=3) || (xx>4&&yy>4)){
				if(yy-xx==1){
					cout<<"1111"<<"\n";
				}else{
					cout<<"1110"<<"\n";
				}
			}else{
				cout<<"1100"<<"\n";
			}
		}else{
			cout<<"1000"<<"\n";
		}
	}
	return 0;
} 
