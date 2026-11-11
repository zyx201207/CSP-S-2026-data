#include<bits/stdc++.h>
using namespace std;
int n,n1,m[4];
char a[4],b[4];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    cin>>n;
    for(int i=1;i<=3;i++){
    	cin>>a[i];
	}
	cin>>n1;
    for(int i=1;i<=3;i++){
    	cin>>b[i];
	}
	if(n==n1){//两张车票对应的座位是否在同一节车厢
		m[1]=1;
		if(a[1]==b[1]&&a[2]==b[2]){//两张车票对应的座位是否在同一节车厢的同一排
			m[2]=1;
			if(a[3]<='C'&&b[3]<='C'){// 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
				m[3]=1;
				if((a[3]=='A'&&b[3]=='B')||(a[3]=='B'&&b[3]=='C')||(a[3]=='F'&&b[3]=='D')||(b[3]=='A'&&a[3]=='B')||(b[3]=='B'&&a[3]=='C')||(b[3]=='F'&&a[3]=='D')){
					m[4]=1;
				}else{
					m[4]=0;
				}
			}else if(a[3]>'C'&&b[3]>'C'){
				m[3]=1;
				if((a[3]=='A'&&b[3]=='B')||(a[3]=='B'&&b[3]=='C')||(a[3]=='F'&&b[3]=='D')||(b[3]=='A'&&a[3]=='B')||(b[3]=='B'&&a[3]=='C')||(b[3]=='F'&&a[3]=='D')){
					m[4]=1;
				}else{
					m[4]=0;
				}
			}else{
				m[3]=0;
				m[4]=0;
			}
		}else{
			m[2]=0;
			m[3]=0;
			m[4]=0;
		}
	}else{
		m[1]=0;
		m[2]=0;
		m[3]=0;
		m[4]=0;
	}
	for(int i=1;i<=4;i++){
		cout<<m[i];
	}
    return 0;
}
