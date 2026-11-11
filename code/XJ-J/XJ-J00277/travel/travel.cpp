#include<cstdio>
char str1[10],str2[10],str3[10],str4[10];
int main()
{
    int i;
    FILE *in = fopen("travel.in","r");
    FILE *out = fopen("travel.out","w");
    fscanf(in,"%s %s %s %s",str1+1,str2+1,str3+1,str4+1);
    bool flag=true;
    for(i=1;i<=2;i++)
    {
        if(str1[i]!=str3[i])
        {
            flag=false;
        }
    }
    if(flag)
    {
        fprintf(out,"1");
    }
    else
    {
        fprintf(out,"0000");
        return 0;
    }
    bool flag2=true;
    for(i=1;i<=2;i++)
    {
        if(str2[i]!=str4[i])
        {
            flag2=false;
        }
    }
    if(flag2)
    {
        fprintf(out,"1");
    }
    else
    {
        fprintf(out,"000");
        return 0;
    }
    bool flag3=false;
    if(str2[3]=='A' || str2[3]=='B' || str2[3]=='C')
    {
        if(str4[3]=='A' || str4[3]=='B' || str4[3]=='C')
        {
            flag3=true;
            fprintf(out,"1");
        }
    }
    if(str2[3]=='D' || str2[3]=='F')
    {
        if(str4[3]=='D' || str4[3]=='F')
        {
            flag3=true;
            fprintf(out,"11");
            return 0;
        }
    }
    if(!flag3)
    {
        fprintf(out,"00");
        return 0;
    }
    if(str2[3]=='A' && str4[3]=='B')
    {
        fprintf(out,"1");
    }
    else if(str2[3]=='B' && str4[3]=='A')
    {
    	fprintf(out,"1");
	}
    else if(str2[3]=='B' && str4[3]=='C')
    {
    	fprintf(out,"1");
	}
    else if(str2[3]=='C' && str4[3]=='B')
    {
    	fprintf(out,"1");
	}
    else
    {
        fprintf(out,"0");
    }
    return 0;
}
