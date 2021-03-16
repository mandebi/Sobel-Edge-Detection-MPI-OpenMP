img = imread("image.jpg");
gray = rgb2gray(img);
resized_gray = imresize(gray, [3000, 3000]);
writematrix(resized_gray, 'input.txt', 'Delimiter', 'tab');