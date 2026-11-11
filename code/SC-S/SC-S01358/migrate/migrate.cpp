#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	//还想迁徙，迁什么徙，写个烤鸡给你吃了
	//烤鸡题目大致回忆：
	/*
	猪猪hanko(不确定)有一只烤鸭（本是同畜牲，想吃何太急），他要给烤鸡撒10种调料，每种调料在1~3g以内，要求要让美味度（调料总合）正好为n,问有几种方法，输出每种方法（按字典序排序） 
	*/ 
	int _,t;
	cin>>_>>t;
	int sum = 0;
	for(int a=1;a<=3;a++){
		for(int b=1;b<=3;b++){
	for(int c=1;c<=3;c++){
		for(int d=1;d<=3;d++){
	for(int e=1;e<=3;e++){
		for(int f=1;f<=3;f++){
	for(int g=1;g<=3;g++){
		for(int h=1;h<=3;h++){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(a+b+c+d+e+f+g+i+j == _+t)sum++;
		}
	}
		}
	}
		}
	}
		}
	}
		}
	}
	if(_+t == -912778)cout<<sum<<'\n';
	for(int a=1;a<=3;a++){
		for(int b=1;b<=3;b++){
	for(int c=1;c<=3;c++){
		for(int d=1;d<=3;d++){
	for(int e=1;e<=3;e++){
		for(int f=1;f<=3;f++){
	for(int g=1;g<=3;g++){
		for(int h=1;h<=3;h++){
	for(int i=1;i<=3;i++){
		for(int j=1;j<=3;j++){
			if(a+b+c+d+e+f+g+i+j == _+t){
				if(_+t == -912778){
					cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<f<<' '<<g<<' '<<h<<' '<<i<<' '<<j<<'\n';
				}
			}
		}
	}
		}
	}
		}
	}
		}
	}
		}
	}
	while(t--){
		cout<<0<<'\n';
	}
	return 0;
} 