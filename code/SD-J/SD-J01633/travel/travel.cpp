#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,aa,b,bb;
	cin>>a>>aa>>b>>bb;
	if(a!=b){//是否是一个车厢 
		cout<<0;//不是一个车厢不可能坐在一起了 
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	else{
		cout<<1;
	}
	char aaa=aa[2],bbb=bb[2],x=aa[0],xx=aa[1],y=bb[0],yy=bb[1];
	if(x==y&&xx==yy){//是否同一排 
		cout<<1;
	}
	else{
		cout<<0;//不是同一排后面不可能坐在一起了 
		cout<<0;
		cout<<0;
		return 0;
	}
	if((aaa<='C'&&bbb<='C')||(aaa>='D'&&bbb>='D')){//是否在过道两侧，都小于C那就是左边，都大于D那就是右边 
		cout<<1;
		int aaaa=(int)(aaa),bbbb=(int)(bbb);
		if(bbbb-aaaa==1||aaaa-bbbb==1){//ascll码相差为一那么就相邻，前面判断了所以不需要判断是不是C或D 
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{//不是的话那就不是过道两侧更不是相邻 
		cout<<0;
		cout<<0;
	}
	
	return 0;
} 
//判断规则：两个座位相邻，当且仅当在同一节车厢的同一排，位于过道的同一侧，且在该侧的
//座位序列中相邻。
