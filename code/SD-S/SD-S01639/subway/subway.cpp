#include<bits/stdc++.h>
using namespace std;
int hyw,line,sta,hywmax,q,ans=0;
int staTi[510]; //地铁站chuzhanshij
int lineGo[500010];
int lineTi[500010];//转转时间 
int head[500010]={0},v[500010],Ti[500010],Next[500010],cnt=0;
int queGo[500010],l,r;
int queTi[500010];
void add(int x,int y,int z){
	cnt++;
	Next[cnt]=head[x];
	v[cnt]=y;
	Ti[cnt]=z;
	head[x]=cnt;
}
int bfs(int start,int end){
	int minTi[500010];//f
	l=0;
	r=0;
	queGo[r]=start;
	queTi[r]=queTi[l];
	minTi[start]=queTi[r];
	r++;
	ans=1e9;
	while(l!=r){
		int nowGo,nowTi;
		nowGo=queGo[l];
		nowTi=queTi[l];
		//cout<<l<<": "<<nowGo<<":"<<nowTi<<endl;
		l++;
		if(nowGo==end){
			ans=min(ans,nowTi);
			continue;
		}
		for(int i=head[nowGo];i!=0;i=Next[i]){
			if(minTi[v[i]]==0||minTi[v[i]]>nowTi+Ti[i]){
				queGo[r]=v[i];
				queTi[r]=nowTi+Ti[i];
				//cout<<"to "<<v[i]<<" "<<queTi[r]<<endl;
				r++;
				minTi[v[i]]=nowTi+Ti[i];
			}
		}
		//cout<<endl;
	}
	return min(minTi[end],ans)+staTi[end]+staTi[start];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>hyw>>line>>sta>>hywmax>>q;
	for(int i=1;i<=sta;i++){
		scanf("%d",&staTi[i]);
	}
	for(int i=1;i<=line;i++){
		cin>>lineGo[0];
		for(int k=1;k<=lineGo[0];k++){
			scanf("%d %d",&lineGo[k],&lineTi[k]);
		}
		for(int k=1;k<=lineGo[0];k++){
			for(int x=1;x<=lineGo[0];x++){
				if(x==k) continue;
				add(lineGo[x],lineGo[k],lineTi[x]+lineTi[k]);
			}
		}
	}
	int x,y,ans;
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		ans=bfs(x,y);
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
