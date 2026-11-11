#include<bits/stdc++.h>
using namespace std;

int id,q;
int n,k,cnt;
int l,r,len,root;
bool is;
int head[1000500],dis[1000500];

struct bbb{
	int to,last;
}a[2000500];

void add( int x,int y ){
	a[++cnt].to=y;
	a[cnt].last=head[x];
	head[x]=cnt;
}

void dfs_1( int now,int fa,int step ){
	if( step>len ){
		l=now;
		len=step;
	}
	for( int i=head[now]; i; i=a[i].last ){
		if( a[i].to==fa ) continue;
		dfs_1( a[i].to,now,step+1 );
	}
}

void dfs_2( int now,int fa,int step ){
	if( step>len ){
		r=now;
		len=step;
	}
	for( int i=head[now]; i; i=a[i].last ){
		if( a[i].to==fa ) continue;
		dfs_2( a[i].to,now,step+1 );
	}
}

void dfs_3( int now,int fa,int step ){
	if( now==r ){
		is=1;
		return;
	}
	for( int i=head[now]; i; i=a[i].last ){
		if( a[i].to==fa ) continue;
		dfs_3( a[i].to,now,step+1 );
		if( is ) break;
	}
	if( is and step==len>>1 ){
		root=now;
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d %d",&id,&q);
	while( q-- ){
		scanf("%d %d",&n,&k);
		memset( head,0,sizeof(head) );
		cnt=0;
		for( int i=1; i<n; ++i ){
			int x,y;
			scanf("%d %d",&x,&y);
			add( x,y );
			add( y,x );
		}
		len=0;
		dfs_1( 1,0,0 );
		len=0;
		dfs_2( l,0,0 );
		is=0;
		len-=k;
		len=max( 0,len );
		len=(len+1)/2;
		printf("%d\n",len);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}