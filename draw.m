function draw(name,suffix,yRange,except)
cd('data');
csvs=dir(strcat('*_',suffix,'.csv'));
len=length(csvs);row=len;
i=1;N=1000:100:30000;

for j=1:len
  file=csvs(j).name;
  for k=1:length(except)
    if strcmp(file,except{k})
      row=row-1;
    end
  end
end

figure;
for j=1:len
  file=csvs(j).name;
  ignore=false;
  for k=1:length(except)
    if strcmp(file,except{k})
      ignore=true;
      break;
    end
  end
  if ignore
    continue;
  end
  data=csvread(file);
  [m,n]=size(data);
  for k=1:n
    subplot(row,n,i);
    scatter(N,data(:,k),'*');
    title(file);
    axis([N(1) N(end) yRange(1) yRange(end)]);
    i=i+1;
  end
end
set(gcf,'PaperUnits','Inches','PaperPosition',[0 0 20 row*3.5]);
cd('..');
print('-djpeg','-r100',name);
end
