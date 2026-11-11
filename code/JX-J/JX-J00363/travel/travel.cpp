char c1[3],s1[4],c2[3],s2[4];
scanf("%s %s %s %s ",c1+1,s1+1,c2+1,s2+1);
if (c1[1]==c2[1] && c1[2]==c2[2]){
    printf("%d","1");
    if (s1[1]==s2[1] && s1[2]==s2[2]){
        printf("%d","1");
        if ((s1[3]=='F' || s1[3]=='D')&&(s2[3]=='F' || s2[3]=='D')){
            printf("%d","1");
            if (max(s1[3],s2[3])-min(s1[3],s2[3]) == 1)
                printf("%d","1");
            else
                printf("%d","0");
        }
        else
            if ((s1[3]>='A' && s1[3]<='C')&&(s2[3]>='A' && s2[3]<='C')){
                printf("%d","1");
                if (max(s1[3],s2[3])-min(s1[3],s2[3]) == 1)
                    printf("%d","1");
                else
                    printf("%d","0");
            }
            else
                printf("%d","00");
    }
    else
        printf("%d","000");
}
else
    printf("%d","0000");
return 0;
