#include<cstdio>
int n;
struct piece{
	int len;
	char c;
}p[200001];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::scanf("%d",&n);
	for(int i=1;i<=n;i++) std::scanf("%d %c",&p[i].len,&p[i].c);
	for(int start=1,end=n;start<=end;){
		if(p[start].c==p[end].c){
			if(p[start].len<p[end].len){p[end].len-=p[start].len;start++;}
			else if(p[start].len==p[end].len){start++;end--;}
			else{p[start].len-=p[end].len;end--;} 
		}else{
			if(p[start].len<p[end].len){ans+=p[start].len;p[end].len-=p[start].len;start++;}
			else if(p[start].len==p[end].len){ans+=p[start].len;start++;end--;}
			else{ans+=p[end].len;p[start].len-=p[end].len;end--;}
		}
	}std::printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
