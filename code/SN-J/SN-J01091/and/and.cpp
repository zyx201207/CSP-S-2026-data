#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,m=0,c=0,cc=0,biggestnum=0,biggestcc=0,num=0,zh=1,kg=0,lf1=0,lf2=0,lfend=0;
	string f1,f2,fend;
	cin>>n>>m;
	while(m>=zh&&c<zh*2){
		zh*=2;
		kg++;
	}
	if(c==zh){
		f2[0]='1';
		for(int j=1;j<=zh;j++){
			f2[j]='0';
		}
	}else{
		for(int j=0;j<=kg;j++){
			if(m==zh){
				f2[j]='1';
				for(int k=0;k<kg;k++){
					f2[j+k]='0';
				}
			}
			f2[j]=c/zh;
			c%=zh;
			zh/=2;
			kg--;
		}
	}
	zh=1,kg=0;
	for(int i=0;i<n;i++){
		zh=1,kg=0,num=0;
		cin>>c;
		cc=c;
		while(c>=zh&&c<zh*2){
			zh*=2;
			kg++;
		}
		if(c==zh){
			f1[0]='1';
			for(int j=1;j<=zh;j++){
				f1[j]='0';
			}
		}else{
			for(int j=0;j<=kg;j++){
				if(c==zh){
					f1[j]='1';
					for(int k=0;k<kg;k++){
						f1[j+k]='0';
					}
				}
				f1[j]=c/zh;
				c%=zh;
				zh/=2;
				kg--;
			}
		}
		lf1=f1.size();
		lf2=f2.size();
		for(int j=0;j<lf1;j++){
			if(f1[j]=='1'&&f2[j]=='1'){
				fend[j]='1';
			}else{
				fend[j]='0';
			}
		}
		zh=1,kg=0;
		lfend=fend.size();
		for(int j=lfend-1;j>=0;j--){
			num=num+(fend[j]*zh);
			zh*=2;
		}
		if(num>biggestnum){
			biggestnum=num;
			biggestcc=cc;
		}
	}
	cout<<biggestcc;
	return 0;
}
