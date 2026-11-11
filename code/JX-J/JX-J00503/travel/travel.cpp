#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

struct{
	int c;
	int p;
	char l;
}m[2];

int jdz(int a){
	if(a<0)return -a;
	return a;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for(int i=0;i<=1;i++){
		cin>>m[i].c>>m[i].p>>m[i].l;
	}
	if(m[0].c==m[1].c){
		cout<<1;
		if(m[0].p==m[1].p){
			cout<<1;
			if((m[0].l<='C'&&m[1].l<='C')||(m[0].l>='D'&&m[1].l>='D')){
				cout<<1;
				if((jdz(int(m[0].l)-int(m[1].l)))==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}

}
