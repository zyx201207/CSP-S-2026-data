#include <cstdio>
#include <cstdint>
#include <cmath>
struct p{
	int32_t sub=0,pos=0;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	auto z = [](char c)->int32_t{
		if('0'<=c&&'9'>=c)
			return c-'0';
		else
			return c-'A'+10;
	};
	p a,b;
	char c;

	for(int i=1;i<=5;i++){
		scanf(" %c",&c);
		if(i<=2)
			a.sub*=16,a.sub+=z(c);
		else
			a.pos*=16,a.pos+=z(c);
	}
	for(int i=1;i<=5;i++){
		scanf(" %c",&c);
		if(i<=2)
			b.sub*=16,b.sub+=z(c);
		else
			b.pos*=16,b.pos+=z(c);
	}
	bool d=false,e=false,f=false,g=false;
	if(a.sub==b.sub){
		d=true;
	}
	if(d&&(a.pos&0xff0)==(b.pos&0xff0)){
		e=true;
	}
	if(d&&e&&(((a.pos&0xf)<=0xc&&(b.pos&0xf)<=0xc)||((a.pos&0xf)>0xc&&(b.pos&0xf)>0xc))){
		f=true;
	}
	if(d&&e&f&&(std::abs(b.pos-a.pos)==1)){
		g=true;
	}
	printf("%d%d%d%d\n",d,e,f,g);
}